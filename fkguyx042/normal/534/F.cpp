//#pragma comment(linker, "/STACK:102400000,102400000")  
#include<cstdio>  
#include<ctype.h>  
#include<algorithm>  
#include<iostream>  
#include<cstring>  
#include<vector>  
#include<cstdlib>  
#include<stack>  
#include<queue>  
#include<set>  
#include<map>  
#include<cmath>  
#include<ctime>  
#include<string.h>  
#include<string>  
#include<sstream>  
#include<bitset>  
using namespace std;  
#define ll long long  
#define ull unsigned long long  
#define eps 1e-8  
#define NMAX 1000000000  
#define MOD 51123987  
#define lson l,mid,rt<<1  
#define rson mid+1,r,rt<<1|1  
#define PI acos(-1)  
#define ALL(x) x.begin(), x.end()  
#define INS(x) inserter(x, x.end())  
template<class T>  
inline void scan_d(T &ret)  
{  
    char c;  
    int flag = 0;  
    ret=0;  
    while(((c=getchar())<'0'||c>'9')&&c!='-');  
    if(c == '-')  
    {  
        flag = 1;  
        c = getchar();  
    }  
    while(c>='0'&&c<='9') ret=ret*10+(c-'0'),c=getchar();  
    if(flag) ret = -ret;  
}  
template<class T> inline T Max(T a, T b){ return a > b ? a : b; }  
template<class T> inline T Min(T a, T b){ return a < b ? a : b; }  
  
int st[5][20],n,m;  
void dfs1(int s, int have, int ge, int pos)  
{  
    if(pos == n)  
    {  
        st[ge][0]++;  
        st[ge][st[ge][0]] = s;  
        return;  
    }  
    dfs1(s,0,ge,pos+1);  
    if(have) dfs1(s|(1<<pos),1,ge,pos+1);  
    else dfs1(s|(1<<pos),1,ge+1,pos+1);  
}  
int a[10],b[25];  
char ans[6][25];  
set<int>ha[20][33];  
bool dfs(int pos,int pre)  
{  
    if(pos == m)  
    {  
        for(int i = 0; i < n; i++)  
            if(a[i] != 0) return false;  
        for(int i = 0; i < n; i++)  
            ans[i][pos] = '\0';  
        return true;  
    }  
    int tmp = 1,pp = 0;  
    for(int i = 0; i < 5; i++)  
    {  
        pp += a[i]*tmp;  
        tmp *= 11;  
    }  
    if(ha[pos][pre].find(pp) != ha[pos][pre].end()) return false;  
    for(int i = 1; i <= st[b[pos]][0]; i++)  
    {  
        int d = st[b[pos]][i];  
        for(int j = 0;j < n; j++)  
            if((d&(1<<j)) && (pre & (1<<j)) == 0)  
                a[j]--;  
        int flag = 0;  
        for(int j = 0; j < n; j++)  
            if(a[j] < 0 || ((m-1-pos)/2+1 < a[j]))  
            {  
                flag = 1;  
                break;  
            }  
        if(flag == 0 && dfs(pos+1,d))  
        {  
            for(int j = 0; j < n; j++)  
                ans[j][pos] = (d&(1<<j)) ? '*' : '.';  
            return true;  
        }  
        for(int j = 0; j < n; j++)  
            if((d&(1<<j)) && (pre & (1<<j)) == 0)  
                a[j]++;  
    }  
    ha[pos][pre].insert(pp);  
    return false;  
}  
  
int main()  
{  
    scanf("%d%d",&n,&m);  
    dfs1(0,0,0,0);  
    for(int i = 0; i < n; i++)  
        scanf("%d",&a[i]);  
    for(int i = n+1; i < 5; i++) a[i] = 0;  
    for(int i = 0; i < m; i++)  
        scanf("%d",&b[i]);  
    for(int i = 0; i < m; i++)  
        for(int j = 0; j < 33; j++)  
            ha[i][j].clear();  
    dfs(0,0);  
    for(int i = 0; i < n; i++)  
        printf("%s\n",ans[i]);  
    return 0;  
}