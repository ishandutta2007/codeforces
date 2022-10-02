#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
 

using namespace std;

struct bit
{
   long long first, second;
};

bool f(const bit& a, const bit&b) {
	return a.first < b.first;
}
int main(){
    int n, d, a, b, x[100000], y[100000];
    vector<bit> v;
    cin >> n >> d >> a >> b;
    for(int i = 0; i < n; i++){
    	cin >> x[i] >> y[i];
    	bit t;
    	t.first = x[i] * a + y[i] * b;
    	t.second = i + 1;
    	v.push_back(t);
    }
    sort(v.begin(), v.end(), f);
    bit t;
    t.first = 1000000001;
    t.second = n;
    v.push_back(t); 
    long long s = 0;
    int l = v.size();
    for(int i = 0; i <= l; i++){
        if(s <= d){
            s += v[i].first;
        }else {
            printf("%d\n", i - 1);
            for(int j = 0; j < i - 1; j++){
                cout << v[j].second << ' ';
            }
            printf("\n");
            return 0;
        }
    }
	return 0;
}