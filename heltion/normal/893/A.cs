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
            int n, k = 3;
            n = Convert.ToInt32(Console.ReadLine());
            for(int i = 1; i <= n; ++i)
            {
                int c = Convert.ToInt32(Console.ReadLine());
                if (c == k)
                {
                    Console.WriteLine("NO");
                    return;
                }
                k = 6 - k - c;
            }
            Console.WriteLine("YES");
        }
    }
}