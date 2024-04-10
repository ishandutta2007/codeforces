#include <bits/stdc++.h>

using namespace std;

int grid[5][5];

int main()
{
    for(int i=0; i<5; i++)
        for(int j=0; j<5; j++)
            scanf("%d", &grid[i][j]);
    int arr[]={0, 1, 2, 3, 4};
    int maxi=0;
    do
    {
        int suma=0;
        suma+=grid[arr[0]][arr[1]];
        suma+=grid[arr[1]][arr[0]];
        suma+=grid[arr[2]][arr[3]];
        suma+=grid[arr[3]][arr[2]];
        suma+=grid[arr[1]][arr[2]];
        suma+=grid[arr[2]][arr[1]];
        suma+=grid[arr[3]][arr[4]];
        suma+=grid[arr[4]][arr[3]];
        suma+=grid[arr[2]][arr[3]];
        suma+=grid[arr[3]][arr[2]];
        suma+=grid[arr[3]][arr[4]];
        suma+=grid[arr[4]][arr[3]];
        maxi=max(maxi, suma);
    }
    while(next_permutation(arr, arr+5));
    printf("%d\n", maxi);
    return 0;
}