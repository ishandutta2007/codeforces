#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define index Index
using namespace std;
typedef long long LL;
int main(){
    int n;
    scanf("%d",&n);
    map<string,int> m;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        m[s]++;
    }
    int cnt=0;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        if(m[s]==0)cnt++;
        else m[s]--;
    }
    printf("%d\n",cnt);
}