#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cstring>
#include <stdlib.h>
#include <string>
#include <ctime>
#include <cassert>


using namespace std;


#define forn(i, n) for (int i = 0; i < int(n); i++)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define forab(i, a, b) for (int i = int(a); i < int(b); i++)
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long ll;
typedef long double ld;

const int INF = 1E9;  //!!
const ld eps = 1e-7;  //!!
    
int n;
vi a, b, c, num, num2;
    
bool good(int mid) {
	int ch = 0, cid = 0;
   	bool f = 1;
   	forn(i, 111) {
   		forn(j, num[i]) {
   			if (i < ch) {
   				f = 0;
   				break;
   			}
   			cid++;
   			if (cid == mid) {
   				cid = 0;
   				ch++;
   			}	
   		}
   		if (!f)
   			break;
   	}

   	return f;
}

int bins() {
	int l = 0, r = n, mid;
	while (r - l > 1) {
		mid = (l + r) >> 1;
		        
		//good func      
		                     
	    if (good(mid))
	    	r = mid;
	    else
	    	l = mid;

    }
    return r;
}

int main() {

    cin >> n;
    a.resize(n);
    num.resize(111);
    forn(i, n) {
    	cin >> a[i];
    	num[a[i]]++;
    }
    //forn(i, 111)
    //	cout << num[i] << '\n';                
	cout << bins();	

    return 0;
}