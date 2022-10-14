/*
AuThOr GaRyMr
*/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define LL long long
#define IT iterator
#define PB push_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
pair<int,int> a[200000+2];
int n;
int main(){
	fastio;
	cin>>n;
	rb(i,1,n)
		cin>>a[i].FIR;
	rb(i,1,n)
		cin>>a[i].SEC;
	sort(a+1,a+1+n);
	priority_queue<int> q;
	int las=0;
	LL sum=0;
	LL res=0;
	rb(i,1,n){
		if(a[i].FIR>las){
			while(!q.empty()&&las<a[i].FIR){
				las++;
				sum-=q.top();
				res+=sum;
				q.pop();
			}
		}
		q.push(a[i].SEC);
		sum+=a[i].SEC;	
		las=a[i].FIR;
	}
	while(!q.empty()){
				sum-=q.top();
				res+=sum;
				q.pop();
	}
	cout<<res<<endl;
	return 0;
}