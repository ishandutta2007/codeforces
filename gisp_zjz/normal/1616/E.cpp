#include<bits/stdc++.h>
#define pb push_back
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
typedef vector<int>vi;
const int M=998244353;
const int maxn=1e6+10;
char s[maxn],t[maxn];
const ll inf=1e18;
int a[maxn],r[26],n,_;
vector<int> p[26];
void add(int x,int y){
    while (x<maxn) a[x]+=y,x+=x&(-x);
}
int qry(int x){
    int ret=0;
    while (x) ret+=a[x],x-=x&(-x);
    return ret;
}
int nxt(int x){
    if (r[x]<p[x].size()) return p[x][r[x]];
    return -1;
}
int findpos(int x){
    return x-qry(x)-1;
}
int main(){
    cin >> _;
    while (_--){
        cin >> n >> s+1 >> t+1;
        vi tmp; tmp.clear();
        for (int i=0;i<26;i++) p[i].clear(),r[i]=0;
        for (int i=1;i<=n;i++) p[s[i]-'a'].pb(i);
        ll ans=inf,now=0;
        int last=n;
        for (int i=1;i<=n;i++){
            for (int j=0;j<t[i]-'a';j++){
                int pos=nxt(j);
                if (pos!=-1) ans=min(ans,now+findpos(pos));
            }
            int pos=nxt(t[i]-'a');
            if (pos==-1) break;
            tmp.pb(pos);
            now+=findpos(pos); add(pos,1);
            r[t[i]-'a']++;
        }
        for (auto x:tmp) add(x,-1);
        if  (ans<inf) printf("%lld\n",ans); else puts("-1");
    }
    return 0;
}