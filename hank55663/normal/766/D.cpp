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
#define N 200005
#define less Less
int f[200005];
int Find(int x){
    if(f[x]==x)return x;
    return f[x]=Find(f[x]);
}
int main(){
    int n,m,q;
    scanf("%d %d %d",&n,&m,&q);
    map<string,int> index;
    for(int i = 0;i<n;i++){
        char c[25];
        scanf("%s",c);
        index[string(c)]=i;
    }
    for(int i = 0;i<2*n;i++)
        f[i]=i;
    for(int i = 0;i<m;i++){
        int op;
        char c1[25],c2[25];
        scanf("%d %s %s",&op,c1,c2);
        int num1=index[string(c1)],num2=index[string(c2)];
        int f1=Find(num1),f1i=Find(num1+n);
        int f2=Find(num2),f2i=Find(num2+n);
        if(op==1){
            if(f2==f1i||f1==f2i){
                printf("NO\n");
            }
            else{
                printf("YES\n");
                f[f2]=f1;
                f[f2i]=f1i;
            }
        }
        else{
            if(f2==f1||f2i==f1i){
                printf("NO\n");
            }
            else{
                printf("YES\n");
                f[f2]=f1i;
                f[f1]=f2i;
            }
        }
    }
    while(q--){
        char c1[25],c2[25];
        scanf("%s %s",c1,c2);
        int num1=index[string(c1)],num2=index[string(c2)];
        int f1=Find(num1),f1i=Find(num1+n);
        int f2=Find(num2),f2i=Find(num2+n);
        if(f1==f2){
            printf("1\n");
        }
        else if(f1==f2i){
            printf("2\n");
        }
        else{
            printf("3\n");
        }
    }
}