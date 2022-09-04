#include<bits/stdc++.h>
//#define Min(a,b,c) min((a),min((b),(c)))
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-11
#define N 200005
#define M
#define pi 3.14159265359
using namespace std;
typedef long long LL;
int main(){
	char c[100010];
	scanf("%s",c);
	int a[3];
	int sum=0;
	memset(a,0,sizeof(a));
	for(int i=0;c[i]!=0;i++){
		int b=c[i]-'0';
		if(b%3==0)
		a[0]++;
		else if(b%3==1)
		a[1]++,sum++;
		else
		a[2]++,sum+=2;
	}
	if(a[0]==0){
		if(a[1]==0){
			if(a[2]<=2){
			printf("-1\n");
			return 0;
			}
		}
		if(a[2]==0){
			if(a[1]<=2){
			printf("-1\n");
			return 0;
			}
		}
	}
	{
		sum%=3;
		if(sum==0)
		printf("%s",c);
		else if(sum==1){
			char s1[100005],s2[100005];
			memset(s1,0,sizeof(s1));
			memset(s2,0,sizeof(s2));
			if(a[1]!=0)
			for(int i=strlen(c)-1;i>=0;i--){
				if(c[i]%3==1){
					for(int j=0,k=0;c[j]!=0;j++)
					if(i!=j)
					s1[k++]=c[j];
					break;
				} 
			}
			if(a[2]>=2){
				int a=-1,b=-1;
				for(int i=strlen(c)-1;i>=0;i--){
					if(c[i]%3==2){
						if(a==-1)
						a=i;
						else if(b==-1)
						b=i;
						else
						break;
					} 
				}
				for(int j=0,k=0;c[j]!=0;j++)
				if(a!=j&&b!=j)
					s2[k++]=c[j];
			}
			int e=0,f=0;
			if(strlen(s1)>0){
				for(e=0;s1[e]!=0;e++)
				if(s1[e]!='0'){
					break;
				}
				if(s1[e]==0)
				{
					printf("0\n");
					return 0;
				}
				if(s1[e]==0)
				e--;
			}
			for(f=0;s2[f]!=0;f++)
				if(s2[f]!='0'){
				break;
			}
			if(s2[f]==0)
			f--;
			if(f<0)
			f++;
			if(strlen(s1)-e>strlen(s2)-f)
			printf("%s",s1+e);
			else
			printf("%s",s2+f);
		}
		else if(sum==2){
			char s1[100005],s2[100005];
			memset(s1,0,sizeof(s1));
			memset(s2,0,sizeof(s2));
			if(a[2]!=0)
			for(int i=strlen(c)-1;i>=0;i--){
				if(c[i]%3==2){
					for(int j=0,k=0;c[j]!=0;j++)
					if(i!=j)
					s1[k++]=c[j];
					break;
				} 
			}
			if(a[1]>=2){
				int a=-1,b=-1;
				for(int i=strlen(c)-1;i>=0;i--){
					if(c[i]%3==1){
						if(a==-1)
						a=i;
						else if(b==-1)
						b=i;
						else
						break;
					} 
				}
				for(int j=0,k=0;c[j]!=0;j++)
				if(a!=j&&b!=j)
					s2[k++]=c[j];
			}
			int e=0,f=0;
			if(strlen(s1)>0){
			for(e=0;s1[e]!=0;e++)
			if(s1[e]!='0'){
				break;
			}
			if(s1[e]==0)
			{
				printf("0\n");
				return 0;
			}
			}
			for(f=0;s2[f]!=0;f++)
				if(s2[f]!='0'){
				break;
			}
			if(s2[f]==0)
			f--;
			if(f<0)
			f++;
			if(strlen(s1)-e>strlen(s2)-f)
			printf("%s",s1+e);
			else
			printf("%s",s2+f);
		}
	}
}/**/