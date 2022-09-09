using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Cs
{
    class Program
    {
        static void Main(string[] args)
        {
            int ans = 0, n = Convert.ToInt32(Console.ReadLine());
            for(int k = 1; k <= 10; ++k)
            {
                if (n % (((1 << k) - 1) * (1 << k - 1)) == 0)
                {
                    ans = ((1 << k) - 1) * (1 << k - 1);
                }
            }
            Console.WriteLine(ans);
        }
    }
}