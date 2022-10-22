#include<bits/stdc++.h>
using namespace std;

int n;

int main() {
    scanf("%d", &n);

    if(n & 1) printf("0");
    else printf("%d", 1<<(n/2));
}