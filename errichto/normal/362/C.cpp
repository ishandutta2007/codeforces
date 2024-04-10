#include<cstdio>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<cstring>
#include<cmath>
using namespace std;
#define pb push_back
#define ll long long
#define ld long double
#define vi vector<int>
#define pii pair<int,int>
#define st first
#define nd second
const int nax=5005;

int n,t[nax];
short int mniejszedo[2][nax][nax],wiekszedo[2][nax][nax];
int ro;
int res=-1,licz;
int najpierw;

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;++i)scanf("%d",&t[i]);
	for(int i=0;i<n;++i)
		for(int j=0;j<i;++j)
			if(t[j]>t[i])najpierw++;
	
	for(int i=t[0];i<n;++i)mniejszedo[ro][0][i]=1;
	for(int i=1;i<n;++i)
		for(int j=0;j<n;++j){
			mniejszedo[ro][i][j]=mniejszedo[ro][i-1][j];
			if(t[i]<=j)mniejszedo[ro][i][j]++;
		}
		
	for(int i=0;i<=t[0];++i)wiekszedo[ro][0][i]=1;
	for(int i=1;i<n;++i)
		for(int j=0;j<n;++j){
			wiekszedo[ro][i][j]=wiekszedo[ro][i-1][j];
			if(t[i]>=j)wiekszedo[ro][i][j]++;
		}
		
	ro=1;
	reverse(t,t+n);
	
	for(int i=t[0];i<n;++i)mniejszedo[ro][0][i]=1;
	for(int i=1;i<n;++i)
		for(int j=0;j<n;++j){
			mniejszedo[ro][i][j]=mniejszedo[ro][i-1][j];
			if(t[i]<=j)mniejszedo[ro][i][j]++;
		}
		
	for(int i=0;i<=t[0];++i)wiekszedo[ro][0][i]=1;
	for(int i=1;i<n;++i)
		for(int j=0;j<n;++j){
			wiekszedo[ro][i][j]=wiekszedo[ro][i-1][j];
			if(t[i]>=j)wiekszedo[ro][i][j]++;
		}
	
	reverse(t,t+n);
	for(int i=0;i<n;++i)
		for(int j=i+1;j<n;++j)
			if(t[i]>t[j]){
				int s=t[i]-t[j]-1;
				s-=((int)(mniejszedo[0][i][t[i]-1]+wiekszedo[0][i][t[j]+1]))-(i+1);
				s-=((int)(mniejszedo[1][n-1-j][t[i]-1]+wiekszedo[1][n-1-j][t[j]+1]))-(n-j);
				//printf("%d,%d  %d\n",i,j,s);
				if(s>res){
					licz=1;
					res=s;
				}
				else if(s==res)licz++;
			}
	printf("%d %d",najpierw-(2*res+1),licz);
	return 0;
}