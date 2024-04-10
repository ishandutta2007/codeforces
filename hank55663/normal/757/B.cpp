#include<bits/stdc++.h>
#define Min(a,b,c) min((a),min((b),(c)))
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pb(x) push_back(x)
#define x first
#define y second
#define N 100005
#define sqr(x) ((x)*(x))
#define EPS 1e-11
#define pi 3.14159265359	
using namespace std;
int isPrime[100005];
vector<int> prime;
void find(){
	for(int i=0;i<100005;i++)
	isPrime[i]=1;
	isPrime[1]=0;
	for(int i=2;i<100005;i++){
		if(isPrime[i]){
			isPrime[i]=prime.size()+1;
			prime.pb(i);
			for(int j=i*2;j<100005;j+=i)
				isPrime[j]=0;
		}
	}
}
int main(){
	find();
	int n;
	scanf("%d",&n);
	int num[100000];
	memset(num,0,sizeof(num));
	for(int i=0;i<n;i++){
		int a;
		scanf("%d",&a);
		for(int j=0;;j++){
			if(isPrime[a]){
				num[isPrime[a]]++;
				break;
			}
			if(a%prime[j]==0)
			{
				num[j+1]++;
				while(a%prime[j]==0)a/=prime[j];
			}
			if(a==1){
				break;
			}
		}
	}
	int ans=1;
	for(int i=0;i<10000;i++)
	ans=max(ans,num[i]);
	printf("%d\n",ans);
}