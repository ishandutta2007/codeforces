#include<cstdio>
int n,k;
inline long long C(int x, int y){
    long long ret=1;
    for(int i=x;i>=x-y+1;--i)ret*=i;
    for(int i=1;i<=y;++i)ret/=i;
    return ret;
}
int main() {
    scanf("%d%d",&n,&k);
    if(k==1)printf("1");
	else if(k==2)printf("%lld",C(n,2)+1);
	else if(k==3)printf("%lld",C(n,2)+C(n,3)*2+1);
	else if(k==4)printf("%lld",C(n,2)+C(n,3)*2+C(n,4)*9+1);
}