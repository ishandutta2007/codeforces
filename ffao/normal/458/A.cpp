#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <queue>
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <ctime> 
#include <cstring> 

using namespace std; 

typedef long long ll; 
typedef pair<int, int> pii;

#define INF 1000000000
#define pb push_back 
#define itr iterator 
#define sz size() 
#define mp make_pair

long long arr1[110000];
long long arr2[110000];
char c;
char str1[110000];
char str2[110000];

void convert(char* str, long long* arr) {
    int n = strlen(str);
    for (int i = 0; i < n; i++) {
        arr[n-i-1] = str[i]-'0';
    }
}

int main() {
    scanf("%s %s", str1, str2); 
    
    convert(str1, arr1);
    convert(str2, arr2);

    for (int i = 100000; i >= 0; i--) {
        arr1[i] -= arr2[i];
    }

    for (int i = 100000; i >= 2; i--) {
        if (arr1[i] > 100000) {
            printf(">\n");
            return 0;
        }
        else if (arr1[i] < -100000){
            printf("<\n");
            return 0;
        }
        arr1[i-1] += arr1[i];
        arr1[i-2] += arr1[i];
    }

    //printf("%lld %lld\n", arr1[1], arr1[0]);
    
    arr1[0] *= 2;
    arr1[0] += arr1[1];

    //printf("%lld %lld\n", arr1[1], arr1[0]);

    if (arr1[0] == 0 && arr1[1] == 0) printf("=\n");
    else if (arr1[0] >= 0 && arr1[1] >= 0) printf(">\n");
    else if (arr1[0] <= 0 && arr1[1] <= 0) printf("<\n");
    else {
        long long f = arr1[0] * arr1[0];
        long long s = arr1[1] * arr1[1] * 5;
        bool bf = f >= s;
        bool bg = arr1[0] >= 0;

        if ((bf && bg) || (!bf && !bg)) printf(">\n");
        else printf("<\n");
    }
}