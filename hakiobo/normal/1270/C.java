import java.io.BufferedReader;
import java.io.InputStreamReader;

public class MakeGood {
    public static void main(String[] args) throws Exception {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int numTrials = Integer.parseInt(in.readLine());
        StringBuilder sb = new StringBuilder();
        for (int trial = 0; trial < numTrials; trial++) {
            int numNums = Integer.parseInt(in.readLine());
            long sum = 0;
            long xor = 0;
            String[] nums = in.readLine().split(" ");
            for (int i = 0; i < numNums; i++) {
                long num = Long.parseLong(nums[i]);
                sum += num;
                xor ^= num;
            }
            long leftMostOne = Long.highestOneBit(sum);
            long mask = (leftMostOne<<1) | (1&sum);
            sum += mask;
            xor ^= mask;
            sb.append(3);
            sb.append('\n');
            sb.append(mask);
            sb.append(' ');
            long newNum = ((xor << 1) - sum) >> 1;
            sb.append(newNum);
            sb.append(' ');
            sb.append(newNum);
            sb.append('\n');

        }
        System.out.print(sb);
    }
}