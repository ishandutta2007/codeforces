#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
int m;
#define Maxn 20
char ch[Maxn];
int num[12],len;
int a[12];
ll f[300010][105];
int main(){
    scanf("%s",ch+1);
    len=strlen(ch+1);
    scanf("%d",&m);
    for(register int i=1;i<=len;++i)num[ch[i]-'0']++;
    for(register int i=1;i<=10;++i)a[i]=a[i-1]+num[i-1];
    for(register int i=1;i<=9;++i)
        if(num[i])f[1<<a[i]][i%m]=1;
    for(register int i=1;i<(1<<len);++i)
        for(register int j=0;j<m;++j)
            if(f[i][j]){
                for(register int k=0;k<=9;++k)
                    for(register int l=a[k];l<a[k+1];++l){
                        if(i&(1<<l))continue;
                        f[i|(1<<l)][(j*10+k)%m]+=f[i][j];
                        break;
                    }
            }
    printf("%lld\n",f[(1<<len)-1][0]);
    return 0;
}