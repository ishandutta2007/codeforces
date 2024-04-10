#include <iostream>
#include <iomanip>
#include <cstdio>
#include <math.h>
#include <algorithm>
#include <queue>
#include <string>
#include <fstream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <ctime>

#define all(x) (x).begin(), (x).end()
#define pb push_back
#define double long double
#define LL long long
#define itn int

using namespace std;

int main(){

//  freopen("combo.in", "r", stdin);
//  freopen("combo.out", "w", stdout);

    string s;
    int k;
    cin >> s >> k;
    for (int i = 0; i < s.length(); i++){
        for (char c = '9'; c > s[i]; c--){
            int j = i + 1;
            while (j < s.length() && s[j] != c && j - i <= k) j++;
            if (j < s.length() && j - i <= k){
                k -= (j - i);
                for (int ij = j - 1; ij >= i; ij--){
                    swap(s[ij], s[ij + 1]);
                }
                break;
            }
        }
    }
    cout << s;

    return 0;
    
}