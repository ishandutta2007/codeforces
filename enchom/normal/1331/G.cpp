#include <iostream>
#include <vector>
#include <stdio.h>
#include <math.h>
using namespace std;

int main()
{
    int i;
    vector<int> v;

    for (i=1;i<=11;i++)
    {
        int a;

        scanf("%d",&a);

        v.push_back(a);
    }

    while(!v.empty())
    {
        int var = v.back();
        v.pop_back();

        double sqa = sqrt(abs(var));
        double ov = pow(var, 3.0) * 5.0;

        double res = ov + sqa;

        if (res > 400.0)
        {
            printf("f(%d) = MAGNA NIMIS!\n", var);
        }
        else
        {
            printf("f(%d) = %.2f\n", var, res);
        }
    }
}