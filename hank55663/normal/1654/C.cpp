#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<__float128,__float128>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
multiset<LL> s;
void solve(){
    s.clear();
    int n;
    scanf("%d",&n);
    LL sum=0;
    for(int i = 0;i<n;i++){
        int x;
        scanf("%d",&x);
        s.insert(x);
        sum+=x;
    }
    priority_queue<LL> pq;
    pq.push(sum);
    while(!pq.empty()){
        LL x=pq.top();
        pq.pop();
        if(s.find(x)!=s.end()){
            s.erase(s.find(x));
            continue;
        }
        if(*s.rbegin()>=x){
            printf("no\n");
            return;
        }
        pq.push(x/2);
        pq.push(x/2+x%2);
    }
    printf("yes\n");
}


int main(){
    int t=1;
  scanf("%d",&t);
    while(t--){
        solve();
    }
}
/*

*/