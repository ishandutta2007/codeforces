#include<bits/stdc++.h>
using namespace std;
#define N 400020
typedef long long ll;
typedef unsigned long long ull;
const ull base=1145141;
int n,m,d[N],cnt;
ll qwq,pvp,qaq,ans;
ull pw[N],f[N];
string s[N];
vector<ull> h[N],q[N];
map<ull,int> A,B,id,mp[N];
ull Hash(vector<ull> &h,int l,int r){if(l>r)return 0;return h[r]-(l==0?0:h[l-1])*pw[r-l+1];}
ull get_hash(string &s){ull h=0;for(int i=0;i<(int)s.length();++i)h=h*base+s[i];return h;}
struct node{int ch[26];}trie[N];
void Merge(map<ull,int> &A,map<ull,int> &B){if(A.size()<B.size())swap(A,B);for(auto [h,w]:B)A[h]+=w;B.clear();}
void dfs(int u){for(int c=0;c<26;++c){int v=trie[u].ch[c];if(!v)continue;dfs(v);Merge(mp[u],mp[v]);}for(auto x:q[u])pvp+=mp[u][x];}
int main(){cin>>n;for(int i=1;i<=n;++i)cin>>s[i];m=s[1].length();for(int i=1;i<=n;++i){h[i].resize(m),h[i][0]=s[i][0];for(int j=1;j<m;++j)h[i][j]=h[i][j-1]*base+s[i][j];}pw[0]=1;for(int i=1;i<=m;++i)pw[i]=pw[i-1]*base;for(int i=1;i<=n;++i){string t=s[i];sort(t.begin(),t.end());++A[f[i]=get_hash(t)]; ++B[h[i][m-1]];if(!id.count(f[i]))id[f[i]]=++cnt;}for(auto [h,w]:A)qwq+=1LL*w*(w-1)/2;ans=(1LL*n*(n-1)/2-qwq)*1337;for(int i=1;i<=n;++i){static set<ull> S;int las,u;u=las=id[f[i]];for(int j=m-1;j>=0;--j){int c=s[i][j]-'a';if(!trie[u].ch[c])trie[u].ch[c]=++cnt;u=trie[u].ch[c];if(!j||s[i][j]<s[i][j-1]){q[las].push_back(!j?0ull:h[i][j-1]);las=u;++d[i];}}++mp[u][0];for(int j=0;j<m;++j)++mp[u][h[i][j]];}for(int i=1;i<=(int)A.size();++i)dfs(i);for(int i=1;i<=n;++i)pvp-=B[h[i][m-1]]*d[i];ans+=pvp;for(auto [h,w]:B)qaq+=1LL*w*(w-1)/2;ans+=(qwq-pvp-qaq)*2;cout<<ans<<'\n';return 0;}