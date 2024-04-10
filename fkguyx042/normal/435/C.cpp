#include <iostream>  
#include <cstdio>  
#include <algorithm>  
#include <cstring>  
  
using namespace std;  
  
const int MAX_N = 1000 + 10;  
  
struct Corner  
{  
    int x, y;  
};  
  
bool cmp(Corner c1, Corner c2)  
{  
    return c1.y > c2.y;  
}  
  
Corner Corners[MAX_N];  
int arr[MAX_N];  
char ans[MAX_N][MAX_N << 1];  
  
int main()  
{  
    memset(Corners, 0, sizeof(Corners));  
    int n, max_y = 0, min_y = 0, sum = 0;  
    scanf("%d", &n);  
    scanf("%d", arr);  
    sum += arr[0];  
    Corners[0].x = arr[0];  
    Corners[0].y = arr[0];  
    max_y = max(max_y, Corners[0].y);  
    min_y = min(min_y, Corners[0].y);  
    for(int i = 1; i < n; i++)  
    {  
        scanf("%d", arr + i);  
        sum += arr[i] ;  
        Corners[i].x = Corners[i - 1].x;  
        Corners[i].y = Corners[i - 1].y;  
        Corners[i].x += arr[i];  
        if(i % 2)  
            Corners[i].y -= arr[i];  
        else  
            Corners[i].y += arr[i];  
        max_y = max(max_y, Corners[i].y);  
        min_y = min(min_y, Corners[i].y);  
    }  
    for(int i = 0; i < max_y - min_y; i++)  
        for(int j = 0; j < sum; j++)  
            ans[i][j] = ' ';  
    int start_x = 0;  
    int start_y = (min_y < 0) ? (max_y - min_y - 1) + min_y : (max_y - 1);  
    for(int i = 0; i < n; i++)  
    {  
        if(i % 2)  
        {  
            for(int j = start_x; j < Corners[i].x; j++)  
                ans[start_y++][j] = '\\';  
            start_x = Corners[i].x;  
            start_y--;  
        }  
        else  
        {  
            for(int j = start_x; j < Corners[i].x; j++)  
                ans[start_y--][j] = '/';  
            start_x = Corners[i].x;  
            start_y++;  
        }  
    }  
    for(int i = 0; i < max_y - min_y; i++)  
        printf("%s\n", ans[i]);  
    return 0;  
}