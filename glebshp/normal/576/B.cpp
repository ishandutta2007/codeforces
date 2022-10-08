#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second

const double pi = acos(-1.0);
const int size = 200 * 1000 + 100;

int p[size];
bool used[size];
int n;
set <int> lens[size];
bool oncycle[size];

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
    	scanf("%d", &p[i]);
    	p[i]--;
    }

    for (int i = 0; i < n; i++)
    	if (p[i] == i) {
    		printf("YES\n");
    		for (int j = 0; j < n; j++)
    			if (i != j)
    				printf("%d %d\n", i + 1, j + 1);

    		return 0;
    	}

    	bool flag;

    	for (int i = 0; i < n; i++) {
    		if (!oncycle[i]) {
    			int ptr = p[i];
    			oncycle[i] = true;
    			int len = 1;
    			while (ptr != i) {
//    				cerr << ptr << ' ' << i << endl;
    				oncycle[ptr] = true;
    				used[ptr] = true;
    				ptr = p[ptr];
    				len++;
    			}

    			lens[len].insert(i);
    		}
    	}

    	flag = (!lens[2].empty());
    	for (int i = 3; i <= n; i += 2)
    		flag = flag && (lens[i].empty());
    	
//    	cerr << "here" << endl;

    	if (flag) {
	    	printf("YES\n");
	    	
	    	for (int i = 0; i < n; i++)
	    		oncycle[i] = false;
	    	for (int i = 0; i < n; i++)
	    		if (p[p[i]] == i) {
	    		    printf("%d %d\n", i + 1, p[i] + 1);
	    		    oncycle[i] = true;
	    		    oncycle[p[i]] = true;

			    	for (int j = 0; j < n; j++) {
    					if (!oncycle[j]) {
		    				int ptr = p[j];
    						oncycle[j] = true;
    						printf("%d %d\n", p[i] + 1, j + 1);
			    			int len = 1;
			    			while (ptr != j) {
		    					if (len & 1)
		    						printf("%d %d\n", i + 1, ptr + 1);
		    					else
		    						printf("%d %d\n", p[i] + 1, ptr + 1);

			    				oncycle[ptr] = true;
			    				used[ptr] = true;
			    				ptr = p[ptr];
		    					len++;

    						}
    				   	}
   		   		}
   		   	   			return 0;

   		   	}
    	}



    printf("NO\n");

    return 0;
}