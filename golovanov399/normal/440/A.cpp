#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{   
    
    int n;
    scanf("%d", &n);
    int x = 0, y;
    for (int i = 0; i < n - 1; i++){
        scanf("%d", &y);
        x ^= y;
        x ^= (i + 1);
    }
    x ^= n;
    cout << x;
    
    return 0;
}