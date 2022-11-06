#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int n;
    int many[5]={0,0,0,0,0};

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int v;
        scanf("%d", &v);
        many[v] ++;
    }

    int ret = 0;

    ret += many[4]; many[4] = 0;

    int nm13 = min(many[1], many[3]);

    ret += nm13;
    many[1] -= nm13;
    many[3] -= nm13;

    ret += many[3];
    many[3] = 0;

    ret += many[2]/2;
    many[2] %= 2;

    ret += (2*many[2]+many[1]+3)/4;
    many[2] = many[1] = 0;

    printf("%d\n", ret);

    return 0;
}