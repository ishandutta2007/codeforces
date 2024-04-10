#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include <bits/stdc++.h>
#include <string>
#include <stdlib.h>
#include <vector>
#include <sstream>
#include <stack>
#include <queue>
#include <cmath>
using namespace std;
int main()
{
    string a, b = "1";
    long long n;
    long long track = 0;
    cin >> n;
    cin >> a;
    if (a=="0"){
    	cout << "0";
	}
	else{
	for (int i = 0; i<a.length(); i++){
		if (a[i]=='0') track++;
	}
    for (int i = 0; i<track; i++){
    	b+='0';
	}
	cout << b;
	}
    return 0;
}