#include <iostream>
#include <fstream> 
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <cassert>
#include <complex>
#include <bitset>
#include <map>
#include <set>
#include <ctime>
#include <cfloat>

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, k, n) for (int i = (int)(k); i < (int)(n); i++)
#define forba(i, n, k) for (int i = (int)(n) - 1; i >= (int)(k); i--)

#define vi vector<int>
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define X first
#define Y second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-8;
const int INF = 1E9;		
const int MAXN = 5111;

int n, T, id, Ti;
ld p[MAXN], t[MAXN], Pi, powP;
ld dp[2][MAXN];
ld sum, mn;
double answer;

int main() {

    cin >> n >> T;
    forn(i, n)
    	cin >> p[i] >> t[i];
    	
    dp[0][0] = 1;
    for (int i = 1; i <= T; i++)
    	dp[0][i] = 0;

    answer = 0;
   	id = 0;
    for (int i = 1; i <= n; i++) {
    	//cout << i << '\n';
    	
    	for (int j = 0; j <= T; j++)
        	dp[id ^ 1][j] = 0;
        	
        Pi = p[i - 1] / 100.0;
        powP = 1;
        Ti = t[i - 1];
        
        forn(j, Ti - 2)
        	powP *= (1.0 - Pi);

        if (p[i - 1] < 100 && Ti != 1) {
			//add temp
        
			sum = dp[id][0];
			mn = 1.0;
			for (int j = 1; j < Ti - 1; j++) {
				dp[id ^ 1][j] = sum * Pi;
				sum *= (1.0 - Pi); 
				sum += dp[id][j];
			}
			
        	for (int j = Ti - 1; j <= T; j++) {
        		//cout << j << ' ' << sum << '\n';
        		
				dp[id ^ 1][j] = sum * Pi;
				sum -= powP * dp[id][j - Ti + 1];
				sum *= (1.0 - Pi);
				sum += dp[id][j];	
			}
        	
			//add luck
       		for (int j = Ti; j <= T; j++)
        		dp[id ^ 1][j] += dp[id][j - Ti] * powP * (1.0 - Pi);
        
        	//add bad luck
        	mn = (1.0 - Pi);
        	for (int j = T - 1; j > T - 1 - (Ti - 1); j--) {
        		if (j < 0)
        			break;
        		answer += (ld)(i - 1) * dp[id][j] * mn;
        		mn *= (1.0 - Pi);	
        	}
		} else {
			for (int j = 1; j <= T; j++)
        		dp[id ^ 1][j] = dp[id][j - 1];        
        }
        
    	//sum levels
    	answer += dp[id ^ 1][T] * i;

    	//cout << answer << '\n';
    	/*
    	for (int j = 0; j <= T; j++)
    		cout << (double)dp[id ^ 1][j] << ' ';
    	cout << '\n';
    	*/
    	id ^= 1;    	
    }
    
    for (int i = 0; i < T; i++)
    	answer += dp[id][i] * n;
    	 
    cout.precision(40);
    cout << answer;
         
//1111        	
	return 0;
}