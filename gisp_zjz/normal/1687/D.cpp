#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<ll,ll>pi;
typedef vector<int> vi;
const int inf=1e9+10;
const int N=2e6;
const int maxn=N*3+5;
const int M=998244353;
void Min(int &x,int y){if (x>y) x=y;}
void Max(int &x,int y){if (x<y) x=y;}
int s[maxn],a[maxn],offset,n,nxt[maxn],pre[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i]; 
    offset=a[1]-1;
    for (int i=1;i<=n;i++) a[i]-=offset,s[a[i]]++;
    pre[0]=0; nxt[N*3+1]=N*3+1;
    for (int i=1;i<=N*3;i++) if (s[i]) pre[i]=i; else pre[i]=pre[i-1];
    for (int i=N*3;i>=1;i--) if (s[i]) nxt[i]=i; else nxt[i]=nxt[i+1];
    for (int i=1;i<=N*3;i++) s[i]+=s[i-1];
    for (int b=1;b<=N;b++){
        int L=0,R=b;
        int now=b+1,base=b+1;
        Min(R,now-pre[now]);
        while (now<N){
            int l=now+base-b,r=now+base*2;
            if (s[l-1]>s[now]) {R=-1;break;}
            Min(R,r-pre[r]);
            Max(L,b-(nxt[l]-l));
            if (L>R) break;
            base++; now=r;
        }
        if (L<=R){
            ll ans=1ll*b*b-1+L-offset;
            if (ans>=0){
                cout << ans << endl;
                break;
            } else if (ans+(R-L)>=0){
                cout << 0 << endl;
                break;
            }
        }
    }
    return 0;
}