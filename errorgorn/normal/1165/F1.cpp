#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int,int> ii;
int n,m;
int arr[200005];
int arr2[200005];
int total;
vector<ii> v;
bool valid(int i){
    for (int x=0;x<200005;x++) arr2[x]=arr[x];
    int curr=i;
    int saved=0;
    int used;
    for (vector<ii>::iterator it=v.begin();it!=v.end();it++){
        if ((*it).first>i) continue;
        curr=min(curr,(*it).first);
        if (arr2[(*it).second] && curr){
            used=min(arr2[(*it).second],curr);
            arr2[(*it).second]-=used;
            curr-=used;
            saved+=used;
        }
    }
    return total-saved<=i;
}
bool cmp(ii i,ii j){
    return i.first>j.first;
}
int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d%d",&n,&m);
    for (int x=1;x<=n;x++){
        scanf("%d",&arr[x]);
        total+=arr[x];
    }
    total<<=1;
    int a,b,c;
    for (int x=0;x<m;x++){
        scanf("%d%d",&a,&b);
        v.push_back(ii(a,b));
    }
    sort(v.begin(),v.end(),cmp);
    a=1,b=total;
    while (a!=b){
        c=(a+b)>>1;
        if (valid(c)){
            if (valid(c-1)){
                b=c-1;
            }
            else{
                a=c;
                b=c;
            }
        }
        else{
            a=c+1;
        }
    }
    printf("%d\n",a);
}