#include <iostream>
#include <fstream>
#include <queue>
#include <cstdlib>
#include <cstddef>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <array>
#include <cmath>
using namespace std;

	

int main (){
	int n, k, *mass;
	cin >> n >> k;
	mass = new int[n];
	for (int i=0; i<n; i++){
		cin >> mass[i];
	}
	int t, a1=0, a2=0, sum=0;
	t = n/k;
	for (int i=0; i<k; i++){
		a1=0;
		a2=0;
		for (int j=0; j<t; j++){
			if (mass[i+j*k]==1){
				a1++;
			} else a2++;
		}
		if (a2<a1) sum+=a2;
		else sum+=a1;
	}
	cout << sum;
	return(0);


}