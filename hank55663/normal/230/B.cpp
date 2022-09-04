#include<bits/stdc++.h>
#define pii pair<int,int>  
#define x first  
#define y second  
#define mp(x,y) make_pair((x),(y))  
#define sqr(x) ((x)*(x))
#define N 100005
typedef long long LL;
using namespace std;
bool isprime[1000005];
vector<long long int> ans;
void find_prime(){
	isprime[1]=0;
	for(long long int i=2;i<1e6+1;i++)
	if(isprime[i]){
		ans.push_back(i*i);
		for(int j=i*2;j<1e6+1;j+=i)
		isprime[j]=0;
	}
} 
int main(){
	int n;
	memset(isprime,1,sizeof(isprime));
	find_prime();
	scanf("%d",&n);
		for(int i=0;i<n;i++){
			long long int a;
			scanf("%I64d",&a);
			if(*lower_bound(ans.begin(),ans.end(),a)==a)
			{
				printf("YES\n");
			}
			else
			printf("NO\n");
		}
	
}