#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0;i<n;i++)
#define repn(i, n) for(int i=1;i<=n;i++)
#define pair<int, int> P;
#define fi first
#define sc second
const int INF = 100000000;

//A is MP
//B is KMP
struct KMP{
	vector<int>A,B,S;
	int j ;
	void init(int sz){
		A.resize(sz,0);
		B.resize(sz,0);
		S.resize(sz,0);
		A[0] = -1;
		B[0] = -1;
	}
	void update(int pos,int val){
		S[pos] = val;
	}
	void make_MP(int pos){
		j = A[pos];
		while(j >= 0 && S[pos] != S[j]) j = A[j];
		
		j++;
		A[pos+1] = j;
	}
};
int dp[8005], n, num[8005];
string str;
int main(){
	fill(num, num+8005, 4);
	repn(i, 999) num[i] = 3;
	repn(i, 99) num[i] = 2;
	repn(i, 9) num[i] = 1;
	cin >> str;
	n = str.size();
	rep(i, 8005) dp[i] = INF;
	dp[0] = 0;
	rep(i, n){
		KMP kaede;
		kaede.init(n-i+3);
		for(int j=i;j<n;j++){
			kaede.update(j-i, str[j]-'a');
			kaede.make_MP(j-i);
			int dif = (j-i+1) - kaede.A[j-i+1], len = 0;
			if((j-i+1)%dif != 0) len = j-i+1;
			else len = dif;
			dp[j+1] = min(dp[j+1], dp[i] + len + num[(j-i+1) / len]);
		}
	}
	printf("%d\n", dp[n]);
}