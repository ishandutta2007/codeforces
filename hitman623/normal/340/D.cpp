#include <bits/stdc++.h>

 #define ll          long long
 #define pb          push_back
 #define pii         pair<int,int>
 #define vi          vector<int>
 #define vii 		vector<pii>
 #define mi 			map<int,int>
 #define mii			map<int,pii>	
 #define all(a)      (a).begin(),(a).end()
 #define x           first
 #define y           second
 #define sz(x)       (int)x.size()
 #define hell        1000000007
 #define endl        '\n'
 #define rep(i,a,b)	for(int i=a;i<b;i++)
using namespace std;

int CeilIndex(std::vector<int> &v, int l, int r, int key) {
	while (r-l > 1) {
		int m = l + (r-l)/2;
		if (v[m] >= key)
			r = m;
		else
			l = m;
	}

	return r;
}

int LongestIncreasingSubsequenceLength(std::vector<int> &v) {
	if (v.size() == 0)
		return 0;

	std::vector<int> tail(v.size(), 0);
    int length = 1; // always points empty slot in tail

    tail[0] = v[0];
    for (size_t i = 1; i < v.size(); i++) {
    	if (v[i] < tail[0])
            // new smallest value
    		tail[0] = v[i];
    	else if (v[i] > tail[length-1])
            // v[i] extends largest subsequence
    		tail[length++] = v[i];
    	else
    		tail[CeilIndex(tail, -1, length-1, v[i])] = v[i];
    }

    return length;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	std::vector<int> v;
	int n;
	cin>>n;
	rep(i,0,n){
		int x;
		cin>>x;
		v.pb(x);
	}
	std::cout <<LongestIncreasingSubsequenceLength(v);
	return 0;
}