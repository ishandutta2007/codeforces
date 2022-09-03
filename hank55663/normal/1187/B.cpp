#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define MXN 10005
#define less Less
#define N (1<<20)
typedef complex<double> C;
int pre[200005][26];
int main(){
    int n;
    scanf("%d",&n);
    char c[200005];
    scanf("%s",c+1);
    for(int i = 1;c[i]!=0;i++){
        for(int j =0;j<26;j++)
            pre[i][j]=pre[i-1][j];
        pre[i][c[i]-'a']++;
    }
    int q;
    scanf("%d",&q);
    while(q--){
        int cnt[26];
        char cc[200005];
        MEM(cnt);
        scanf("%s",cc);
        for(int i = 0;cc[i]!=0;i++){
            cnt[cc[i]-'a']++;
        }
        int Max=n,Min=0;
        while(Max>Min+1){
            int mid=(Max+Min)/2;
            int ok=1;
            for(int i =0;i<26;i++){
                if(cnt[i]>pre[mid][i])
                    ok=0;
            }
            if(ok)Max=mid;
            else Min=mid;
        }
        printf("%d\n",Max);
    }
}
/*
1 
2 6 
3 5 
4
*/