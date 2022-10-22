#include<bits/stdc++.h>
using namespace std;

const int N=2e5+100;
char s[N];
int sta1[N],sta2[N],tot1,tot2;

bool cmp(int n1,int n2) {return (n1<n2);}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--){
		int A,B,C,D;
		scanf("%d%d%d%d",&A,&B,&C,&D);
		scanf("%s",s+1);
		int len=A+B+2*(C+D);
		int Sum=0;
		for(int i=1;i<=len;i++)
			if(s[i]=='A') Sum++;
		if(Sum!=A+C+D){
			printf("NO\n");
			continue;
		}
		
		Sum=tot1=tot2=0;
		for(int i=1;i<len;i++){
			if(s[i]!=s[i+1]){
				int id=i+1;
				while(id<len&&s[id]!=s[id+1]) id++;
				if(id%2==i%2){
					Sum=Sum+(id-i)/2;
				}
				else{
					if(s[i]=='A'){
						sta1[++tot1]=(id-i)/2;
					}
					else{
						sta2[++tot2]=(id-i)/2;
					}
				}
				i=id;
			}
		}
		
		sort(sta1+1,sta1+tot1+1,cmp);
		sort(sta2+1,sta2+tot2+1,cmp);
		
		for(int i=1;i<=tot1;i++){
			if(C>=sta1[i]+1) C=C-sta1[i]-1,sta1[i]=0;
		}
		for(int i=1;i<=tot2;i++){
			if(D>=sta2[i]+1) D=D-sta2[i]-1,sta2[i]=0;
		}
		
		for(int i=1;i<=tot1;i++) Sum+=sta1[i];
		for(int i=1;i<=tot2;i++) Sum+=sta2[i];
		
		if(Sum<C+D){
			printf("NO\n");
		}
		else{
			printf("YES\n");
		}
	}
	
	return 0;
}