#include<bits/stdc++.h>
#define pb push_back
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
typedef vector<int>vi;
const int maxn=2e5+10;
const int M=998244353;
char s[maxn][100];
bool f[100];
int cnt[1<<15],ans,n,m,p,_,a[20];
mt19937_64 gen(time(0));

int main(){
    cin >> n >> m >> p;
    for (int i=0;i<n;i++) cin >> s[i];
    _=20;
    while (_--){
        int id=gen()%n;
        p=0;
        for (int i=0;i<m;i++) if (s[id][i]=='1') a[p++]=i;
        for (int i=0;i<(1<<p);i++) cnt[i]=0;
        for (int i=0;i<n;i++){
            int mask=0;
            for (int j=0;j<p;j++) if (s[i][a[j]]=='1') mask|=1<<j;
            cnt[mask]++;
        }
        for (int i=0;i<p;i++)
            for (int j=0;j<(1<<p);j++)
                if (j&(1<<i)) cnt[j^(1<<i)]+=cnt[j];
        for (int i=0;i<(1<<p);i++) if (cnt[i]*2>=n) {
            int res=__builtin_popcount(i);
            if (ans<res){
                ans=res;
                memset(f,0,sizeof(f));
                for (int j=0;j<p;j++) if (i&(1<<j)) f[a[j]]=1;
            }
        }
    }
    for (int i=0;i<m;i++) cout << f[i]; cout << endl;
    return 0;
}