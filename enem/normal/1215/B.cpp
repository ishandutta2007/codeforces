#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int prefixes_such_that_their_product_is_positive = 1;
    int prefixes_such_that_their_product_is_negative = 0;

    bool current_prefix_positive = true;

    long long subarrays_such_that_their_product_is_positive = 0;
    long long subarrays_such_that_their_product_is_negative = 0;

    for(int i=0; i<n; i++)
    {
        int t;
        cin>>t;

        if( t < 0 ) current_prefix_positive = !current_prefix_positive;

        if(current_prefix_positive)
        {
            subarrays_such_that_their_product_is_positive += prefixes_such_that_their_product_is_positive;
            subarrays_such_that_their_product_is_negative += prefixes_such_that_their_product_is_negative;

            prefixes_such_that_their_product_is_positive++;
        }
        else
        {
            subarrays_such_that_their_product_is_positive += prefixes_such_that_their_product_is_negative;
            subarrays_such_that_their_product_is_negative += prefixes_such_that_their_product_is_positive;

            prefixes_such_that_their_product_is_negative++;
        }
    }

    cout<<subarrays_such_that_their_product_is_negative<<' '<<subarrays_such_that_their_product_is_positive;

    return 0;
}