#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
  
#define ll          long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;

int num_of_primes[5000006];
int spf[5000006];
bool is_prime[5000006];
int num_of_primes_in_factorial[5000006];

void process_spf(){
	for(int i=1;i<=5000000;i++) is_prime[i]=true;
	for(int i=1;i<=5000000;i++) spf[i]=i;
	for(int d=2;d<=5000000;d++){
		if(is_prime[d]==false) continue;
		for(int num=2*d;num<=5000000;num+=d){
			is_prime[num]=false;
			spf[num]=min(spf[num], d);
		}
	}
}

void process_num_of_primes(){
	for(int i=1;i<=5000000;i++){
		int num=i;
		while(num!=1){
			num_of_primes[i]++;
			num = num / spf[num];
		}
	}
}


void solve(){
    process_spf();
    process_num_of_primes();
    for(int i=1;i<=5000000;i++){
    	num_of_primes_in_factorial[i] = num_of_primes[i] + num_of_primes_in_factorial[i-1];
    }
    int q;
    cin>>q;
    while(q--){
    	int a,b;
    	cin>>a>>b;
    	int answer = num_of_primes_in_factorial[a] - num_of_primes_in_factorial[b];
    	cout<<answer<<endl;
    }
}
 
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}