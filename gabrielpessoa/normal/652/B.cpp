#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	vector<int> arr(n, 0);
	for(int i = 0; i < n; i++) {
	    scanf("%d", &arr[i]);
	}
	sort(arr.begin(), arr.begin() + n);
	vector<int> arrAux(n, 0);
	for(int i = 0; i < (n / 2); i++) {
	    arrAux[i*2] = arr[i];
	    if(n % 2 == 0) {
	        arrAux[i*2+1] = arr[(n / 2) + i];
	    } else {
	        arrAux[i*2+1] = arr[(n / 2) + i + 1];
	    }
	}
	if(n % 2 != 0) {
	    arrAux[n - 1] = arr[n / 2];
	}
	bool zsorted = true;
	for(int i = 1; i < n; i++) {
	    if(i % 2 == 0) {
	        if(arrAux[i] > arrAux[i-1]) {
	            zsorted = false;
	            break;
	        }
	    } else {
	        if(arrAux[i] < arrAux[i-1]) {
	            zsorted = false;
	            break;
	        }
	    }
	}
	if(!zsorted) {
	    printf("Impossible");
	} else {
	    for(int i = 0; i < n; i++) {
	        if(i != 0) {
	            printf(" ");
	        }
	        printf("%d", arrAux[i]);
	    }
	}
	return 0;
}