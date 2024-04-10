#include<cstdio>
using namespace std;
char c[100];int n,z[255],i;
int main(){
    scanf("%d",&n);
    scanf("%s",c);
    for(i=0;i<n;i++)z[c[i]]=1;
    for(i=0;i<26;i++)
        if((!z['a'+i])&&(!z['A'+i])){
            printf("NO");return 0;
        }
    printf("YES");
}