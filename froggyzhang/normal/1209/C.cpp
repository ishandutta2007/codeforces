#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 200020
inline int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x*f;
}
char s[N];
int T,n,a[N],ans[N];
int main(){
	T=read();
	while(T--){
		n=read();
		scanf("%s",s+1);
		for(int i=1;i<=n;i++){
			a[i]=s[i]-'0';
		}
		
		for(int i=0;i<=9;i++){
			int small=0,big=0;
			int lsm=0,lsb=n;
			bool ok=1;
			for(int j=1;j<=n;j++){
				if(a[j]<i){
					if(a[j]<small){
						ok=0;
						break;
					}
					ans[j]=1;
					lsm=max(lsm,j);
					small=a[j];
				}
				else if(a[j]>i){
					if(a[j]<big){
						ok=0;
						break;
					}
					ans[j]=2;
					lsb=min(lsb,j);
					big=a[j];
				}
			}
			for(int j=1;j<=n;j++){
				if(a[j]==i){
					if(j<lsb){
						ans[j]=2;
					}
					else if(j>lsm){
						ans[j]=1;
					}
					else{
						ok=0;
						break;
					}
				}
			}
			if(ok){
				for(int j=1;j<=n;j++){
					printf("%d",ans[j]);
				}
				printf("\n");
				goto l;
			}
		}
		printf("-\n");
		l:
			continue;
	}
	return 0;
}
/*
1
12 13
1 3 4 2 4 6 3 6 8 2 5 7 9
1 3 4 2 4 6 3 6 8 2 5 7 9
1 3 4 2 4 6 3 6 8 2 5 7 9
1 3 4 2 4 6 3 6 8 2 5 7 9
1 3 4 2 4 6 3 6 8 2 5 7 9
1 3 4 2 4 6 3 6 8 2 5 7 9
1 3 4 2 4 6 3 6 8 2 5 7 9
1 3 4 2 4 6 3 6 8 2 5 7 9
1 3 4 2 4 6 3 6 8 2 5 7 9
1 3 4 2 4 6 3 6 8 2 5 7 9
1 3 4 2 4 6 3 6 8 2 5 7 9
1 3 4 2 4 6 3 6 8 2 5 7 9
*/