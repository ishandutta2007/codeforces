#include<cstdio>
int n,t[1005],a;
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",&a);
        t[a]++;
    }
    for(int i=1;i<=1000;++i)if(t[i]>(n+1)/2)return !printf("NO");
    return !printf("YES");
}