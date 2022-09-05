#include<cstdio>
#include<algorithm>
using namespace std;
int n,r,l,r0=-1,r1=-1,l0=-1,l1=-1;
char s[500005];
int main()
{
    scanf("%d%s",&n,s);
    for(int i=0;i<n;++i){
        if(s[i]=='R'){
            r++;
            if(r0==-1)r0=i+1;
            r1=i+1;
        }
        if(s[i]=='L'){
            l++;
            if(l0==-1)l0=i+1;
            l1=i+1;
        }
    }
    if(r>0 && l>0) printf("%d %d",r0,r1);
    else if(r>0) printf("%d %d",r0,r1+1);
    else printf("%d %d",l1,l0-1);
    return 0;
}