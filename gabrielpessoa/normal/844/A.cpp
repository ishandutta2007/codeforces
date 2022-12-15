#include <bits/stdc++.h>
using namespace std;

int main() {
	char word[1005];
	int k, l;
	bool arr[30];
	memset(arr, 0, 30);
	scanf("%s %d", word, &k);
	l = strlen(word);
	if(k > l) {
	    puts("impossible");
	} else {
	    for(int i = 0; i < l && k > 0; i++) {
	        if(!arr[word[i] - 97]) {
	            k--;
	            arr[word[i] - 97] = true;
	        }
	    }
	    printf("%d", k);
	}
	return 0;
}