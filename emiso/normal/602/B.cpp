#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <queue>
#include <map>

#define w1 while(1)
#define pint(n) printf("%d\n",n)
#define fill(n,m) memset(n,m,sizeof(n))

using namespace std;

int main()
{
    int i,n,data[100100];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&data[i]);
    }

    map<int,int> freq;
    map<int,int>::iterator it;

    freq.insert(pair<int,int>(data[0],1));
    int maior = data[0];
    int menor = data[0];
    int len = 1;
    int maiorlen = 1;
    int j = 0;
    for(int i=1;i<n;i++) {

        if(freq.find(data[i]) == freq.end()) {
            freq.insert(pair<int,int>(data[i],1));
            if(data[i] > maior) maior = data[i];
            if(data[i] < menor) menor = data[i];
        }
        else freq[data[i]]++;

        len++;

        if(maior - menor <= 1) {
            if(len > maiorlen) maiorlen = len;
        }

        else {
            while(maior- menor > 1) {
                if(freq[data[j]] == 1) {
                    freq.erase(data[j]);
                    if(data[j] == menor)
                        menor = freq.begin()->first;
                    if(data[j] == maior) {
                        it = freq.end();
                        it--;
                        maior = it->first;
                    }
                }
                else freq[data[j]]--;
                j++;
                len--;
            }
        }
    }
    if(len > maiorlen) maiorlen = len;
    printf("%d\n",maiorlen);
    return 0;
}