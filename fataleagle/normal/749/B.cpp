#include <bits/stdc++.h>

using namespace std;

int X[3];
int Y[3];

int getX(int a, int b, int c)
{
    return X[a]+(X[b]-X[a])+(X[c]-X[a]);
}

int getY(int a, int b, int c)
{
    return Y[a]+(Y[b]-Y[a])+(Y[c]-Y[a]);
}

int main()
{
    for(int i=0; i<3; i++)
        scanf("%d%d", X+i, Y+i);
    printf("3\n");
    printf("%d %d\n", getX(0, 1, 2), getY(0, 1, 2));
    printf("%d %d\n", getX(1, 0, 2), getY(1, 0, 2));
    printf("%d %d\n", getX(2, 1, 0), getY(2, 1, 0));
    return 0;
}