#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector <pair<long long,long long> > pontos;

int main()
{
    long long n,r,avg,soma=0,ctotal,ponto,custo,i;
    long long ecs=0;
    cin >> n >> r >> avg;
    ctotal=n*avg;
    for(i=0;i<n;i++)
    {
                    cin >> ponto >> custo;
                    pontos.push_back(make_pair(custo,ponto));
                    soma+=ponto;
    }
    sort(pontos.begin(),pontos.end());
    i=0;
    while(soma<ctotal)
    {
                      ecs = ecs + min(ctotal-soma,r-pontos[i].second)*pontos[i].first;
                      soma = soma + min(ctotal-soma,r-pontos[i].second);
                      i++;
    }
    cout << ecs;
    return 0;
}