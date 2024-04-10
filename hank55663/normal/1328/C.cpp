#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define x first
#define LL long long 
#define y second
#define sqr(x) ((x)*(x))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pdd pair<double,double>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
int main() {
	int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        char c[50005];
        scanf("%s",c);
        char a[50005],b[50005];
        int bb=0;
        MEM(a);
        MEM(b);
        //int nowa=0,nowb=0;
        for(int i = 0;c[i]!=0;i++){
            if(bb){
                a[i]='0';
                b[i]=c[i];
            }
            else{
                if(c[i]=='1')a[i]='1',b[i]='0',bb=1;
                else if(c[i]=='2'){
                        a[i]='1',b[i]='1';
                }
                else{
                    a[i]='0',b[i]='0';
                }
            }
        }
        printf("%s\n",a);
        if(b[0]=='0'&&b[1]!=0)printf("%s\n",b+1);
        else printf("%s\n",b);
    }
}