#include<bits/stdc++.h>  
using namespace std;  
const int maxn=200011;  
const int inf=1<<27;  
#define LL long long  
#define P pair<int,int>  
#define pb push_back  
#define cl(a,b) memset(a,b,sizeof(a));  
  
  
char s[maxn];  
int op[27];  
int main(){  
    int n,m;  
    while(~scanf("%d%d",&n,&m)){  
        scanf("%s",s);  
        for(int i=0;i<27;i++)op[i]=i;  
        for(int i=0;i<m;i++){  
            char a[2],b[2];  
            scanf("%s%s",a,b);  
            swap(op[a[0]-'a'],op[b[0]-'a']);  
        }  
        for(int i=0;i<n;i++){  
            for(int j=0;j<27;j++)if(op[j]==s[i]-'a'){  
                printf("%c",j+'a');  
            }  
        }  
        printf("\n");  
    }  
    return 0;  
}