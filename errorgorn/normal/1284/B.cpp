#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int,int> ii;
int n;
vector<int> v[100005];
vector<ii> info;

long long arr[1000005]; //initialize to 0, this is 1-indexed
void update(int i,long long j){ //adds j to ith term
    while (i<1000005){
        arr[i]+=j;
        i+=(i&(-i));
    }
}
long long query(int i){ //calculate the sum of the 0-i terms
    long long k=0;
    while (i>0){
        k+=arr[i];
        i-=(i&(-i));
    }
    return k;
}


int main(){
    scanf("%d",&n);
    long long ans=0;
    int s,t;
    ii temp;
    int rem=n;
    for (int x=0;x<n;x++){
        scanf("%d",&s);
        temp=ii(1000000000,-1);
        for (int y=0;y<s;y++){
            scanf("%d",&t);
            if (!v[x].empty() && v[x].back()<t){
                temp=ii(-2,-2);
            }
            if (temp!=ii(-2,-2)){
                temp.first=min(temp.first,t);
                temp.second=max(temp.second,t);
            }
            v[x].push_back(t);
        }
        //printf("%d %d\n",temp.first,temp.second);
        if (temp==ii(-2,-2)){
            ans+=rem*2-1;
            rem--;
        }
        else{
            info.push_back(temp);
        }
    }
    
    for (auto &it:info){
        update(it.first+1,1);
    }
    
    for (auto &it:info){
        ans+=query(it.second);
    }
    
    printf("%lld\n",ans);
    
}