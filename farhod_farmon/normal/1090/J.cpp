#include <bits/stdc++.h>

#define fi first
#define se second
#define ll long long
#define mp make_pair

const int N = 200200;
const int MAXN = 200200;
const int B = 19;

using namespace std;

string t;
int kek[N];
vector < int > v[N];

pair < int ,int > C[MAXN];
int S[MAXN][B+1],c[MAXN],ord[MAXN],n;
bool cmp(int x,int y){
  return (C[x]<C[y]);
}
bool cmp1(int x,int y){
  return (S[x][B]<S[y][B]);
}
void pre(string s){
  n=s.size();
  s="#"+s;
  for(int i=1;i<=n;i++)
    S[i][0]=(s[i]-'a'+1);
  for(int j=1;j<=B;j++){
    for(int i=1;i<=n;i++)
      C[i]=mp(S[i][j-1],(i+(1<<(j-1))<=n?S[i+(1<<(j-1))][j-1]:-1)),c[i]=i;
    sort(c+1,c+n+1,cmp);
    for(int i=1;i<=n;i++)
      S[c[i]][j]=S[c[i-1]][j]+(C[c[i]]!=C[c[i-1]]);
  }
}
int lcp(int x,int y){
  int res=0;
  for(int j=B;j>=0;j--)
    if(x<=n and y<=n and S[x][j]==S[y][j]){
      res+=(1<<j);
      x+=(1<<j);y+=(1<<j);
    }
  return res;
}
ll get(vector<int>v){
  sort(v.begin(), v.end(),cmp1);
  ll ans=0;
  for(int i=0;i<int(v.size());i++)
    ans+=(n-v[i]+1);
  for(int i=0;i<int(v.size())-1;i++)
    ans-=lcp(v[i],v[i+1]);
  return ans;
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        string s;
        cin >> s >> t;
        string f = t + "#" + s;
        vector < int > z(f.size());
        z[0] = 0;
        for(int i = 1, l = 0, r = 0; i < f.size(); i++){
                if(i <= r){
                        z[i] = min(r - i + 1, z[i - l]);
                }
                while(i + z[i] < f.size() && f[z[i]] == f[i + z[i]]){
                        z[i]++;
                }
                if(i + z[i] - 1 > r){
                        l = i;
                        r = i + z[i] - 1;
                }
        }
        z.push_back(0);
        for(int i = t.size() + 2; i <= f.size(); i++){
                kek[i]++;
                kek[i + z[i]]--;
                if(z[i] < t.size()){
                        v[i + z[i]].push_back(z[i] + 1);
                }
        }
        pre(t);
        long long ans = 0;
        for(int i = 1; i < N; i++){
                kek[i] += kek[i - 1];
                ans += kek[i] > 0;
                if(!v[i].empty()){
                        ans += get(v[i]);
                }
        }
        cout << ans << "\n";
}