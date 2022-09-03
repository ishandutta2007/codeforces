#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
#define last Last
#define MXN 200005
const int mod=998244353;
void solve(){
    int n;
    scanf("%d",&n);
    int c[200005];
    for(int i = 0;i<n;i++)scanf("%d",&c[i]);
    deque<int> a,b;
    int mid=c[0];
    for(int i = 1;i<n;i++){
        if(c[i]>mid){
            a.pb(mid);
            if(b.size()){
                if(b.front()<c[i]){
                    printf("NO\n");
                    return;
                }
                if(b.front()==c[i])
                b.pop_front();
            }
            mid=c[i];
        }
        else if(c[i]<mid){
            b.push_front(mid);
            if(a.size()){
                if(a.back()>c[i]){
                    printf("NO\n");
                    return;
                }
                if(a.back()==c[i])
                a.pop_back();
            }
            mid=c[i];
        }
    }
    printf("YES\n");
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--)
        solve();
}
/*
2 3 5 6 1 4
*/