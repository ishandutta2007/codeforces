8.times do
    row = gets
    7.times do |j|
        if row[j] == row[j + 1]
            puts "NO"
            exit(0)
        end
    end
end
puts "YES"