5.times do |i|
    a = gets.split.map(&:to_i)
    5.times do |j|
        if a[j] == 1
            puts (2 - i).abs() + (2 - j).abs()
            exit 0
        end
    end
end