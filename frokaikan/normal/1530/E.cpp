#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=(a);i<=(n);i++)
#define per(i,a,n) for(int i=(n);i>=(a);i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
template<class T> bool chmax(T &a, const T &b) {if(a<b) {a=b; return 1;} return 0;}
template<class T> bool chmin(T &a, const T &b) {if(b<a) {a=b; return 1;} return 0;}
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int maxn = 100000;
const int inf = 0x3f3f3f3f;
const int mod = 1000000007;

//header
char s[maxn+5];

int cnt[30];

int main()
{
    int cas; scanf("%d",&cas); while(cas--)
    {
        scanf("%s",s+1);
        int n=strlen(s+1);
        rep(i,1,26) cnt[i]=0;
        rep(i,1,n) cnt[s[i]-'a'+1]++;
        bool check_same=0;
        rep(i,1,26) if(cnt[i]==n) check_same=1;
        if(check_same) puts(s+1);
        else
        {
            int mark=-1;
            rep(i,1,26) if(cnt[i]==1) {mark=i; break;}
            if(mark!=-1)
            {
                cnt[mark]=0;
                putchar('a'+mark-1);
                rep(i,1,26) while(cnt[i]--) putchar('a'+i-1);
                puts(""); 
            }
            else
            {
                int x=-1;
                rep(i,1,26) if(cnt[i]) {x=i; break;}
                assert(x!=-1);
                int y=x+1;
                while(cnt[y]==0) y++;
                if(cnt[x]<=n-cnt[x]+2)
                {
                    s[1]=s[2]=x;
                    cnt[x]-=2;
                    rep(i,1,cnt[x]) 
                    {
                        s[2+i*2]=x;
                        while(cnt[y]==0) y++;
                        cnt[y]--;
                        s[2+i*2-1]=y;
                    }
                    rep(i,cnt[x]*2+3,n)
                    {
                        while(cnt[y]==0) y++;
                        cnt[y]--;
                        s[i]=y;
                    }
                }
                else
                {
                    if(cnt[x]+cnt[y]==n)
                    {
                        s[1]=x; cnt[x]--;
                        rep(i,2,1+cnt[y]) s[i]=y;
                        rep(i,cnt[y]+2,n) s[i]=x;
                    }
                    else
                    {
                        int z=y+1;
                        s[1]=x; cnt[x]--;
                        s[2]=y; cnt[y]--;
                        int ptr=2;
                        while(cnt[x]) cnt[x]--,s[++ptr]=x;
                        while(cnt[z]==0) z++;
                        s[++ptr]=z; cnt[z]--;
                        rep(i,ptr+1,n) 
                        {
                            while(cnt[y]==0) y++;
                            cnt[y]--;
                            s[i]=y;
                        } 
                    }
                }
                
                rep(i,1,n) s[i]+='a'-1;
                puts(s+1);
            }
        }
    }
	return 0;
}