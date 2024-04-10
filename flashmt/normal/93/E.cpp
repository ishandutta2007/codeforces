#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

vector <int> a;
int k;
long long n,f[101][100001];

long long calc(int pos,long long x)
{
	if (pos==k) return x;
	if (x<=100000 && f[pos][x]>=0) return f[pos][x];
	long long re=calc(pos+1,x)-calc(pos+1,x/a[pos]);	
	if (x<=100000) f[pos][x]=re;
	return re;
}

int main()
{
	int x;
	cin >> n >> k;
	for (int i=1;i<=k;i++) cin >> x, a.push_back(x);
	sort(a.begin(),a.end());
	reverse(a.begin(),a.end());
	memset(f,-1,sizeof(f));
	cout << calc(0,n) << endl;
	return 0;
}