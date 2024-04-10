import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class Gluttony892D {
    public static void main(String[] args) throws IOException {
        FastScanner in = new FastScanner();
        int n = in.nextInt();
        ArrayList<Integer> originalArray = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            originalArray.add(in.nextInt());
        }
        /*int[] newArray = new int[n];

        long[] sums = new long[(int) Math.pow(2, n)];
        for (int i = 0; i < sums.length; i++) {
            int j = i;
            long sum = 0;
            for (int k = 0; k < n; k++) {
                if (j % 2 == 1) {
                    sum += originalArray.get(k);
                }
                j = j / 2;
            }
            sums[i] = sum;
        }


        newArray[0] = originalArray.get(1);
        originalArray.remove(1);

        for (int i = 1; i < n; i++) {
            boolean nothingWorks = true;
            for (int j = 0; j < originalArray.size(); j++) {
                boolean works = true;
                newArray[i] = originalArray.get(j);
                for (int k = (int) Math.pow(2, i); k < Math.pow(2, i + 1); k++) {
                    int cur = k;
                    long sum = 0;
                    if (k == (int) Math.pow(2, n) - 1) continue;
                    for (int l = 0; l <= i; l++) {
                        if (cur % 2 == 1) {
                            sum += newArray[l];
                        }
                        cur = cur / 2;
                    }
                    if (sum == sums[k]) {
                        works = false;
                        break;
                    }
                }
                if (works) {
                    originalArray.remove(j);
                    nothingWorks = false;
                    break;
                }
            }
            if (nothingWorks) {
                System.out.println(-1);
                return;
            }
        }

        for (int i = 0; i < n; i++) {
            System.out.print(newArray[i] + " ");
        }
        System.out.println();*/
        ArrayList<Integer> sorted = new ArrayList<>(originalArray);
        Collections.sort(sorted);
        for (int i = 0; i < n; i++) {
            int original = originalArray.get(i);
            int index = (sorted.indexOf(original) + 1) % n;
            int newVal = sorted.get(index);
            System.out.print(newVal + " ");
        }
        System.out.println();
    }

    public static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(String s) {
            try {
                br = new BufferedReader(new FileReader(s));
            } catch (FileNotFoundException e) {
                // TODO Auto-generated catch block
                e.printStackTrace();
            }
        }

        public FastScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String nextToken() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    // TODO Auto-generated catch block
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        String nextLine() {
            st = null;
            try {
                return br.readLine();
            } catch (IOException e) {
                // TODO Auto-generated catch block
                e.printStackTrace();
            }
            return null;
        }

        int nextInt() {
            return Integer.parseInt(nextToken());
        }

        long nextLong() {
            return Long.parseLong(nextToken());
        }

        double nextDouble() {
            return Double.parseDouble(nextToken());
        }
    }
}