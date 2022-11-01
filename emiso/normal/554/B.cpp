#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <queue>

#define w1 while(1)
#define pint(n) printf("%d\n",n)
#define fill(n,m) memset(n,m,sizeof(n))

using namespace std;

vector <string> linha;

int main()
{
    int i,j,n;
    string str;
    cin >> n;
    for(i=0;i<n;i++){
            cin >> str;
            linha.push_back(str);
    }
    sort(linha.begin(),linha.end());

    int maior = 1;
    int count = 1;

    for(i=1;i<n;i++){
        if(linha[i]== linha[i-1]) count++;
        else {
            if(count > maior) maior = count;
            count = 1;
        }
    }
    if(count > maior) maior = count;
    cout << maior;
    return 0;
}