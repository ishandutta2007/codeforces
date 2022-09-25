#include <cstdio>
#include <vector>
#include <unordered_set>
#include <utility>
using namespace std;
typedef pair<int,int> ii;
int n,m;
int arr[300005];
vector<ii> v;
unordered_set<long long> s;
void test(int i){
    //printf("%d:\n",i);
    ii counter=ii(-1,-1);
    for (vector<ii>::iterator it=v.begin();it!=v.end();it++){
        //printf("%d %d %d %d\n",(*it).first,(*it).second,counter.first,counter.second);
        if ((*it).first!=i && (*it).second!=i){
            if (counter.first==-1){
                counter=(*it);
            }
            else if (counter.second!=-1){
                if (counter.first==(*it).first || counter.first==(*it).second){
                    counter.second=-1;
                }
                else if (counter.second==(*it).first || counter.second==(*it).second){
                    (*it).first=(*it).second;
                    (*it).second=-1;
                }
                else {
                    return;
                }
            }
            else{
                if (counter.first!=(*it).first && counter.first!=(*it).second){
                    return;
                }
            }
        }
    }
    printf("YES\n");
    exit(0);
}
int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d%d",&m,&n);
    int a,b;
    for (int x=0;x<n;x++){
        scanf("%d%d",&a,&b);
        if (a>b) swap(a,b);
        if (s.count((a<<30)+b)){
            x--;
            n--;
            continue;
        }
        s.insert((a<<30)+b);
        v.push_back(ii(a,b));
        arr[a]++;
        arr[b]++;
    }
    for (int x=1;x<=m;x++){
        if (arr[x]>=(n>>1)){
            test(x);
        }
    }
    printf("NO\n");
}