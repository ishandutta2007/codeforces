#include <iostream> 
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>


using namespace std;

int main() {
    string s;
    int n;
    string s3[1000];
    string s2[1000];
    cin >> s;
    scanf("%d", &n);
    int t = 0;
    int k = s.size();
    for(int i = 0; i < n; i++){
    	cin >> s2[i];
    	if(k <= s2[i].size()){
    		bool b = true;
    		for(int j = 0; j < k; j++){
               if(s[j] != s2[i][j]){
               	b = false;
               }
    		}
    		if(b){
    			s3[t] = s2[i];
    			t++;
    		}
    	}
    }    
    sort(s3, s3 + t);
    if(t == 0){
    	cout << s << "\n";
    } else {
    	cout << s3[0] << "\n";
    }


    return 0;
}