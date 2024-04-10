#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <string.h> 
#include <cstdio>


using namespace std;
bool lesss(const pair<int, int> &p1, const pair<int, int> &p2) {
 return p1.second < p2.second;
}

int main()
{   
    int n;
    scanf("%d", &n);
    vector < pair <int, int> > v(n+1);
    for(int i = 1; i<=n; i++){
      v[i].first = i;
    }
    for(int i = 1; i<=n; i++){
      scanf("%d", &v[i].second);
    }

    sort(v.begin(), v.end(), lesss);

    for(int i =1; i<=n; i++){
        printf("%d ", v[i].first);
    }
    return 0;
}